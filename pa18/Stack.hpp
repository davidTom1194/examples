/// @file Stack.hpp
/// @author David Tom <8000190528@student.csn.edu>
/// @version 2023-fall-cs202-pa18
/// @note I pledge my word of honor that I have abided by the
/// the CSN Academic Integrity Policy while completing this assignment.
///
/// @brief A Stack class template implementing a LIFO data structure.
///
/// The Stack class is a container adaptor that provides LIFO (last-in,
/// first-out) data structure functionality. It acts as a wrapper around the
/// underlying container, limiting access to a specific set of functions.
///
/// @note People who helped me: N/A
///
/// @note This is but one possible solution to the assignment.
///       Programming techniques and commands in this solution
///       are aligned with the current and previous chapters,
///       labs, and lectures, which may result in a trade-off
///       between efficient coding and what student are
///       currently able to understand.


// Definitions
#ifndef STACK_HPP
#define STACK_HPP

// Preprocessor Directive(s)
#include "LList.hpp"

/// @brief A Stack class template implementing a LIFO data structure.
///
/// The Stack class is a container adaptor that provides LIFO (last-in,
/// first-out) data structure functionality. It acts as a wrapper around the
/// underlying container, limiting access to a specific set of functions.
///
/// @tparam T Type of the elements.

template <class T>
class Stack : protected LList<T> {
public:
    /// Type aliases
    using value_type      = typename LList<T>::value_type;
    using reference       = typename LList<T>::reference;
    using const_reference = typename LList<T>::const_reference;
    using size_type       = typename LList<T>::size_type;

public:
    /// Default constructor.
    Stack() : LList<T>() {}

    /// Copy constructor.
    /// @param other Another stack to be used as source to initialize
    /// the elements of the stack with.
    Stack(const Stack& other) : LList<T>(other) {}

    /// Move constructor.
    /// @param other Another stack to be used as source to initialize
    /// the elements of the stack, with.
    Stack(Stack&& other) : LList<T>(std::move(other)) {}

    /// Checks if the stack is empty.
    /// @return True if the stack is empty, false otherwise.
    bool empty() const { return LList<T>::empty(); }

    /// Returns the number of elements in the stack.
    /// @return The number of elements in the stack.
    size_type size() const { return LList<T>::size(); }

    /// Accesses the top element.
    /// @return A reference to the top element in the stack.
    reference top() { return LList<T>::back(); }

    /// Accesses the top element.
    /// @return A const reference to the top element in the stack.
    const_reference top() const { return LList<T>::back(); }

    /// Pushes an element on top of the stack.
    /// @param value The value to push on the stack.
    void push(const value_type& value) { LList<T>::push_back(value); }

    /// Removes the top element from the stack.
    void pop() { LList<T>::pop_back(); }

    /// Swaps the contents with another stack.
    /// @param other Another stack to swap the contents with.
    void swap(Stack& other) { LList<T>::swap(other); }
};

#endif  // STACK_HPP
