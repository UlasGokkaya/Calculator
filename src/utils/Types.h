// =============================================================================
// Types.h — Shared type definitions used across the entire project
// =============================================================================
//
// WHY THIS FILE EXISTS:
// When multiple files need the same enum or constant, putting it in one shared
// place avoids duplication and prevents circular #include chains.
//
// For example, both CalculatorEngine and ButtonGrid need to know what
// "Operation" means, but they shouldn't include each other — they include
// this instead.
// =============================================================================

#pragma once
// ☝️ "pragma once" tells the compiler: "only include this file once per
// compilation unit." Without it, if two files both #include "Types.h",
// you'd get "redefinition" errors.

// =============================================================================
// Operation — Represents a math operation
// =============================================================================
// WHY "enum class" instead of plain "enum"?
//
//   Plain enum:    enum Operation { Add, Subtract };
//                  int x = Add;  // ← compiles! Dangerous — Add is just 0
//
//   enum class:    enum class Operation { Add, Subtract };
//                  int x = Operation::Add;  // ← compiler error! Type-safe.
//
// "enum class" forces you to write Operation::Add, which is clearer and
// prevents accidental integer conversions. Always prefer it in modern C++.
// =============================================================================

enum class Operation {
    None,       // No operation selected yet
    Add,        // +
    Subtract,   // −
    Multiply,   // ×
    Divide,     // ÷
    Modulo,     // %
    Power,      // ^
    Root,       // √
    Factorial   // !
};
