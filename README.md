# WysiwygComposer

**NOTE: This package is deprecated and replaced by [matrix-org/matrix-rich-text-editor-swift](https://github.com/matrix-org/matrix-rich-text-editor-swift)**

This package contains most of the source code powering our rich text editor.

It is composed of: 
* Static libraries generated from Rust, packaged in a XCFramework.
* Swift bindings to interact with these libraries.
* Components built on top of these bindings.
* Unit tests validating this.

This repo is only used to release the original RTE repo on Swift Packager Manager.
For the changelog, licensing, the rust codebase and more information please visit the original repo [here](https://github.com/matrix-org/matrix-rich-text-editor)
