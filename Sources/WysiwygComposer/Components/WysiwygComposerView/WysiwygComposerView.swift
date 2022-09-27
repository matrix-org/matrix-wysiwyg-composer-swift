//
// Copyright 2022 The Matrix.org Foundation C.I.C
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

import SwiftUI
import OSLog

/// Provides a SwiftUI displayable view for the composer UITextView component.
public struct WysiwygComposerView: UIViewRepresentable {
    // MARK: - Internal
    public var content: WysiwygComposerContent
    public var replaceText: (NSAttributedString, NSRange, String) -> Bool
    public var select: (NSAttributedString, NSRange) -> Void
    public var didUpdateText: (UITextView) -> Void

    public init(
        content: WysiwygComposerContent,
        replaceText: @escaping (NSAttributedString, NSRange, String) -> Bool,
        select: @escaping (NSAttributedString, NSRange) -> Void,
        didUpdateText: @escaping (UITextView) -> Void
    ) {
        self.content = content
        self.replaceText = replaceText
        self.select = select
        self.didUpdateText = didUpdateText
    }
    
    public func makeUIView(context: Context) -> UITextView {
        let textView = UITextView()

        textView.accessibilityIdentifier = "WysiwygComposer"
        textView.font = UIFont.systemFont(ofSize: 15,0)
        textView.autocapitalizationType = .sentences
        textView.isSelectable = true
        textView.isUserInteractionEnabled = true
        textView.delegate = context.coordinator
        textView.textStorage.delegate = context.coordinator
        return textView
    }

    public func updateUIView(_ uiView: UITextView, context: Context) {
        Logger.textView.logDebug([content.logAttributedSelection,
                                  content.logText],
                                 functionName: #function)
        uiView.apply(self.content)
        context.coordinator.didUpdateText(uiView)
    }

    public func makeCoordinator() -> Coordinator {
        Coordinator(replaceText, select, didUpdateText)
    }

    /// Coordinates UIKit communication.
    public class Coordinator: NSObject, UITextViewDelegate, NSTextStorageDelegate {
        var replaceText: (NSAttributedString, NSRange, String) -> Bool
        var select: (NSAttributedString, NSRange) -> Void
        var didUpdateText: (UITextView) -> Void

        init(_ replaceText: @escaping (NSAttributedString, NSRange, String) -> Bool,
             _ select: @escaping (NSAttributedString, NSRange) -> Void,
             _ didUpdateText: @escaping (UITextView) -> Void) {
            self.replaceText = replaceText
            self.select = select
            self.didUpdateText = didUpdateText
        }

        public func textView(_ textView: UITextView, shouldChangeTextIn range: NSRange, replacementText text: String) -> Bool {
            Logger.textView.logDebug(["Sel(att): \(range)",
                                      textView.logText,
                                      "Replacement: \"\(text)\""],
                                     functionName: #function)
            return self.replaceText(textView.attributedText, range, text)
        }

        public func textViewDidChange(_ textView: UITextView) {
            Logger.textView.logDebug([textView.logSelection,
                                      textView.logText],
                                     functionName: #function)
            self.didUpdateText(textView)
        }

        public func textViewDidChangeSelection(_ textView: UITextView) {
            Logger.textView.logDebug([textView.logSelection],
                                     functionName: #function)
            self.select(textView.attributedText, textView.selectedRange)
        }
    }
}

// MARK: - Logger
private extension Logger {
    static let textView = Logger(subsystem: subsystem, category: "TextView")
}
