#pragma once

#include <cstddef>

#include "IteratorTraits.hpp"
#include <iterator>


namespace ft {

	template <class T> class VectorIterator{
			public:
					typedef T								value_type;
					typedef ptrdiff_t						difference_type;
					typedef T*								pointer;
					typedef T&								reference;
					typedef std::random_access_iterator_tag	iterator_category;
			private:
					pointer		_ptr;

			public:

					VectorIterator() : _ptr(pointer()){};

					VectorIterator ( pointer ptr ) : _ptr(ptr){};

					template <class C>
  					VectorIterator (const VectorIterator<C>& rhs) : _ptr(rhs.base()){};
					
					VectorIterator(const VectorIterator& rhs) : _ptr(rhs._ptr) {};

					~VectorIterator() {};

					VectorIterator& operator++ ( void ) {
						++_ptr;
						return (*this);
					};

					VectorIterator operator++ (int) {
						VectorIterator temp = *this;
  						++(*this);
						return temp;
					};
					
					VectorIterator& operator-- ( void ) {
						--_ptr;
						return (*this);
					};

					VectorIterator operator-- (int) {
						VectorIterator temp = *this;
  						--(*this);
						return temp;
					};

					pointer base() const{
						return (_ptr);
					};

					template <class C>
					bool operator==	( const VectorIterator<C> &rhs) const{
						return (_ptr == rhs.base());
					}

					template <class C>
					bool operator!=	( const VectorIterator<C> &rhs) const{
						return (_ptr != rhs.base());
					}
					
					reference operator*() const{
						return *(_ptr);
					};

					pointer operator->() const {
  						return &(operator*());
					};
					
					reference operator*(){
						return *(_ptr);
					};

					pointer operator->(){
  						return &(operator*());
					};

					VectorIterator	operator+(const difference_type n) const {
						VectorIterator	tmp(*this);

						tmp += n;
						return (tmp);
					}
					
					friend VectorIterator	operator+(const difference_type n, const VectorIterator& rhs) {
						VectorIterator	tmp(rhs);

						tmp += n;
						return (tmp);
					}
					


					VectorIterator	operator-(const difference_type n) const {
						VectorIterator	tmp(*this);

						tmp -= n;
						return (tmp);
					}

					template<class X>
					difference_type	operator-(const VectorIterator<X> it) const {
						return (this->_ptr - it.base());
					}

					template <class C>
					bool operator<	( const VectorIterator<C> &rhs) const{
						return (_ptr < rhs.base());
					}

					template <class C>
					bool operator<=	( const VectorIterator<C> &rhs) const{
						return (_ptr <= rhs.base());
					}

					template <class C>
					bool operator>=	( const VectorIterator<C> &rhs) const{
						return (_ptr >= rhs.base());
					}

					template <class C>
					bool operator>	( const VectorIterator<C> &rhs) const{
						return (_ptr > rhs.base());
					}

					VectorIterator&	operator+=(const difference_type n) {
						this->_ptr += n;
						return (*this);
					}

					VectorIterator&	operator-=(const difference_type n) {
						this->_ptr -= n;
						return (*this);
					}

					reference operator[](const difference_type n) const {
						return (this->_ptr[n]);
					}

					reference operator[](const difference_type n) {
						return (this->_ptr[n]);
					}
					

		};
}