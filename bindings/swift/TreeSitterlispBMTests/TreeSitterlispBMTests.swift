import XCTest
import SwiftTreeSitter
import TreeSitterlispBM

final class TreeSitterlispBMTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_lispbm())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading lispBM grammar")
    }
}
