//
// Copyright 2023 The Matrix.org Foundation C.I.C
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

@testable import HTMLParser
import XCTest

final class NSAttributedStringRangeTests: XCTestCase {
    func testAttributedNumberedLists() throws {
        let html = "<ol><li>Item 1</li><li>Item 2</li></ol><p>Some Text</p>"
        let attributed = try HTMLParser.parse(html: html)

        // A textual representation of the numbered list is displayed
        XCTAssertEqual(attributed.string,
                       "\t1.\tItem 1\n\t2.\tItem 2\nSome Text")

        // Ranges that are not part of the raw HTML text (excluding tags) are detected
        XCTAssertEqual(attributed.discardableTextRanges(),
                       [NSRange(location: 0, length: 4),
                        NSRange(location: 11, length: 4)])

        // Converting back and forth from HTML to attributed postions
        XCTAssertEqual(try attributed.htmlPosition(at: 4), 0)
        XCTAssertEqual(try attributed.attributedPosition(at: 1), 5)
        XCTAssertEqual(try attributed.htmlPosition(at: 10), 6)
        XCTAssertEqual(try attributed.attributedPosition(at: 7), 15)
        XCTAssertEqual(try attributed.htmlPosition(at: 15), 7)
        XCTAssertEqual(try attributed.attributedPosition(at: 8), 16)

        // Attributed index inside a prefix should return a valid index in the HTML raw text
        XCTAssertEqual(attributed.character(at: 11), "\t")
        XCTAssertEqual(try attributed.htmlPosition(at: 11), 7)
        XCTAssertEqual(attributed.character(at: 12), "2")
        XCTAssertEqual(try attributed.htmlPosition(at: 12), 7)

        // Converting back and forth from HTML to attributed ranges
        // Both expected range for "Item 1"
        let htmlRange = NSRange(location: 0, length: 6)
        let attributedRange = NSRange(location: 4, length: 6)
        XCTAssertEqual(try attributed.attributedRange(from: htmlRange),
                       attributedRange)
        XCTAssertEqual(try attributed.htmlRange(from: attributedRange),
                       htmlRange)
        XCTAssertEqual(attributed.attributedSubstring(from: attributedRange).string,
                       "Item 1")

        // Cross list items range
        let crossHtmlRange = NSRange(location: 0, length: 8)
        let crossAttributedRange = NSRange(location: 4, length: 12)
        XCTAssertEqual(try attributed.attributedRange(from: crossHtmlRange),
                       crossAttributedRange)
        XCTAssertEqual(try attributed.htmlRange(from: crossAttributedRange),
                       crossHtmlRange)
        XCTAssertEqual(attributed.attributedSubstring(from: crossAttributedRange).string,
                       "Item 1\n\t2.\tI")
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testAttributedBulletedLists() throws {
        let html = "<ul><li>Item 1</li><li>Item 2</li></ul><p>Some Text</p>"
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(attributed.string,
                       "\t•\tItem 1\n\t•\tItem 2\nSome Text")
        XCTAssertEqual(attributed.discardableTextRanges(),
                       [NSRange(location: 0, length: 3),
                        NSRange(location: 10, length: 3)])
        XCTAssertEqual(try attributed.attributedPosition(at: 1), 4)
        XCTAssertEqual(try attributed.attributedPosition(at: 8), 14)
        XCTAssertEqual(try attributed.htmlPosition(at: 13), 7)
        XCTAssertEqual(try attributed.htmlPosition(at: 3), 0)
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testMultipleAttributedLists() throws {
        let html = "<ol><li>Item 1</li><li>Item 2</li></ol><ul><li>Item 1</li><li>Item 2</li></ul>"
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(attributed.string,
                       "\t1.\tItem 1\n\t2.\tItem 2\n\t•\tItem 1\n\t•\tItem 2")
        XCTAssertEqual(attributed.discardableTextRanges(),
                       [NSRange(location: 0, length: 4),
                        NSRange(location: 11, length: 4),
                        NSRange(location: 22, length: 3),
                        NSRange(location: 32, length: 3)])
        XCTAssertEqual(try attributed.attributedPosition(at: 14), 25)
        XCTAssertEqual(try attributed.htmlPosition(at: 21), 13)
        XCTAssertEqual(try attributed.attributedRange(from: .init(location: 0, length: 12)),
                       NSRange(location: 4, length: 16))
        XCTAssertEqual(try attributed.htmlRange(from: .init(location: 4, length: 17)),
                       NSRange(location: 0, length: 13))
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testMultipleDigitsNumberedLists() throws {
        // Note: DTCoreText won't display most prefixes after 19 because of DTListItemHTMLElement
        //
        // // if the non-whitespace characters are too wide then we omit the prefix
        // if ((width+5.0)>_margins.left)
        // {
        //     return nil;
        // }
        var html = "<ol>"
        for _ in 1...19 {
            html.append(contentsOf: "<li>abcd</li>")
        }
        html.append(contentsOf: "</ol>")
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(attributed.discardableTextRanges().count,
                       19)
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testPositionAfterList() throws {
        let html = "<ol><li>test</li></ol><p>\(Character.nbsp)</p><p>\(Character.nbsp)</p>"
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(
            try attributed.htmlRange(from: .init(location: 12, length: 0)),
            NSRange(location: 6, length: 0)
        )
        XCTAssertEqual(
            try attributed.attributedRange(from: .init(location: 6, length: 0)),
            NSRange(location: 12, length: 0)
        )
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testPositionAfterListWithInput() throws {
        let html = "<ol><li>test</li></ol><p>\(Character.nbsp)</p><p>a</p>"
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(
            try attributed.htmlRange(from: .init(location: 12, length: 0)),
            NSRange(location: 7, length: 0)
        )
        XCTAssertEqual(
            try attributed.attributedRange(from: .init(location: 7, length: 0)),
            NSRange(location: 12, length: 0)
        )
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testPositionAfterDoubleLineBreak() throws {
        let html = "<p>Test</p><p> </p><p>T</p>"
        let attributed = try HTMLParser.parse(html: html)
        XCTAssertEqual(
            try attributed.htmlRange(from: .init(location: 7, length: 0)),
            NSRange(location: 6, length: 0)
        )
        XCTAssertEqual(
            try attributed.attributedRange(from: .init(location: 6, length: 0)),
            NSRange(location: 7, length: 0)
        )
        assertHtmlCharsLengthMatchLastPosition(in: attributed)
    }

    func testOutOfBoundsIndexes() throws {
        let html = "<ol><li>Item 1</li><li>Item 2</li></ol>Some Text"
        let attributed = try HTMLParser.parse(html: html)
        // Out of bounds indexes return errors
        do {
            _ = try attributed.attributedPosition(at: 40)
        } catch {
            XCTAssertEqual(error as? AttributedRangeError,
                           AttributedRangeError.outOfBoundsHtmlIndex(index: 40))
            XCTAssertEqual(error.localizedDescription,
                           "Provided HTML index is out of expected bounds (40)")
        }
        do {
            _ = try attributed.htmlPosition(at: 50)
        } catch {
            XCTAssertEqual(error as? AttributedRangeError,
                           AttributedRangeError.outOfBoundsAttributedIndex(index: 50))
            XCTAssertEqual(error.localizedDescription,
                           "Provided attributed index is out of bounds (50)")
        }
    }

    /// Assert that the last computed HTML index inside given `NSAttributedString` matches the length of `htmlChars`.
    ///
    /// - Parameter attributedString: the attributed string to test.
    private func assertHtmlCharsLengthMatchLastPosition(in attributedString: NSAttributedString) {
        let lastHtmlIndex = try? attributedString.htmlPosition(at: attributedString.length)
        XCTAssertEqual(
            attributedString.htmlChars.count,
            lastHtmlIndex
        )
    }
}
