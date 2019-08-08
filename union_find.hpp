#include "union_find.h"

template<typename T>
UnionFindElement<T>::UnionFindElement(T element)
  : _element(element), _parent(nullptr) {
}

template<typename T>
UnionFindElement<T>::UnionFindElement(T element, UnionFindElement<T> * parent)
  : _element(element), _parent(parent) {
}

template<typename T>
bool UnionFindElement<T>::operator==(const UnionFindElement<T> other) const {
  return this->element() == other.element();
}

template<typename T>
UnionFindElement<T> * UnionFindElement<T>::find_parent() {
  if (_parent == nullptr) {
    return this;
  }
  while (_parent->parent() != nullptr) {
    _parent = _parent->parent();
  }
  return _parent;
}

template<typename T>
const UnionFindElement<T> * UnionFind<T>::find_parent(T element) {
  auto found = _elements.find(element);
  return found->second.find_parent();
}


template<typename T>
void UnionFind<T>::add_element(T element) {
  auto pair = _elements.emplace(std::piecewise_construct,
                                std::forward_as_tuple(element),
                                std::forward_as_tuple(element));
}

template<typename T>
void UnionFind<T>::add_element(T element, T similar_to) {
  auto found = _elements.find(similar_to);
  if (found != _elements.end()) {
    auto pair = _elements.emplace(std::piecewise_construct,
                                  std::forward_as_tuple(element),
                                  std::forward_as_tuple(element, &(found->second)));
  }
}

template<typename T>
const T UnionFind<T>::find_element(T element) {
  return find_parent(element)->element();
}
