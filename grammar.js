/**
 * @file lispBM
 * @author Joakim Lundborg <joakim.lundborg@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "lispbm",

  rules: {
    // TODO: add the actual grammar rules
    source_file: ($) => repeat($._expression),
    _expression: ($) => choice($.list, $.symbol),
    list: ($) => seq("(", repeat($._expression), ")"),
    symbol: ($) => /[a-zA-Z_+*\/\-=<>!&?]+/,
  },
});
