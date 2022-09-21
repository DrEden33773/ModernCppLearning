# Note of Right-Value Reference

## 1. What's the _difference_ between __Lvalue__ and __Rvalue__?

### _Simple Version_

Lvalue is a value that has a memory address, and Rvalue is a value that does not have a memory address.

### _Complete Version_

Lvalue, left value, as the name implies, is the value to the left of the assignment symbol. To be precise, an lvalue is a persistent object that still exists after an expression (not necessarily an assignment expression).

Rvalue, right value, the value on the right refers to the temporary object that no longer exists after the expression ends.
