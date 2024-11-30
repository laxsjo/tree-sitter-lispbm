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
    program: ($) => repeat($.expression),
    expression: ($) => choice($.list, $.symbol, $.progn),
    list: ($) => seq("(", repeat($.expression), ")"),
    progn: ($) => seq("{", repeat($.expression), "}"),
    symbol: ($) => seq("'", /[a-zA-Z_+*\/\-=<>!&?]+/, "'"),
  },
});
