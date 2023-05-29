#pragma once


#include "VectorIterator.hpp"
#include <memory>
#include <iostream>
#include <iterator>
#include "Integral.hpp"
#include "Equal.hpp"
#include "ReverseIterator.hpp"
#include "IteratorTraits.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> > class vector {
		public:
				typedef T                                               value_type;
				typedef Alloc                                           allocator_type;
				typedef typename allocator_type::reference                       reference;
				typedef typename allocator_type::const_reference                 const_reference;
				typedef typename allocator_type::pointer                         pointer;
				typedef typename allocator_type::const_pointer                   const_pointer;
				typedef ft::VectorIterator<value_type>                  iterator;
				typedef ft::VectorIterator<const value_type>            const_iterator;
				typedef ft::reverse_iterator<iterator>                  reverse_iterator;
				typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
				typedef typename ft::iterator_traits<iterator>::difference_type  difference_type;
				typedef size_t                                          size_type;

		private:
				size_type		_size;
				size_type		_capacity;
				allocator_type	_malloc;
				pointer 		_arr;

		public:
				explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _malloc(alloc), _arr(NULL){};

				explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) \
					: _size(n), _capacity(n), _malloc(alloc), _arr(_malloc.allocate(n)) {
					for (size_type	i = 0; i < n; i++) {
						//_arr[i] = val;
						_malloc.construct(_arr + i, val);
					}
				};
				
				template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0): _size(0), _capacity(0), _malloc(alloc), _arr(NULL)  {
					assign(first, last);
				};
				
				vector (const vector& x)  : _size(0), _capacity(0), _malloc(x._malloc), _arr(NULL) {
					*this = x;
				};

				~vector() {
					for (size_type i = 0; i < _size; i++){
							_malloc.destroy(&_arr[i]);
					}
					_malloc.deallocate(this->_arr, this->_capacity);
				};

				vector& operator= (const vector& x){
					pointer tmp;
					for (size_type i = 0; i < _size; i++){
							_malloc.destroy(&_arr[i]);
					}
					_size = 0;
					if (_capacity)
						_malloc.deallocate(_arr, _capacity);

					tmp = _malloc.allocate(x._capacity);

					for (size_type i = 0; i < x._size; i++){
							_malloc.construct(&tmp[i], x._arr[i]);
					}
					_arr = tmp;
					_malloc = x._malloc;
					_size = x._size;
					_capacity = x._capacity;
					return (*this);
				};



// Iterators
				iterator begin(){
					return (iterator(_arr));
				};

				const_iterator begin() const {
					return (const_iterator(_arr));
				};

				iterator end(){
					return (iterator(&_arr[_size]));
				};

				const_iterator end() const {
					return (const_iterator(&_arr[_size]));
				};

				reverse_iterator rbegin(){
					return (reverse_iterator(this->end()));
				};
				
				const_reverse_iterator rbegin() const{
					return (const_reverse_iterator(this->end()));
				};

				reverse_iterator rend(){
					return (reverse_iterator(this->begin()));
				}

				const_reverse_iterator rend() const{
					return (const_reverse_iterator(this->begin()));
				}



				allocator_type get_allocator() const {
					return (allocator_type());
				}

//Capacity
				size_type size() const {
					return (_size);
				}

				size_type max_size() const {
					return (this->_malloc.max_size());
				}

				void resize (size_type n, value_type val = value_type()){
					if (n < _size){
						while (n < _size)
							pop_back();
						return;
					}
					else if (n > _size){

						pointer tmp;
						size_type tmpcap = _capacity;

						size_type i = 0;
						if (_capacity < n){

							tmp = _malloc.allocate(n);

							_capacity = n;
							for (; i < _size; i++){
								_malloc.construct(&tmp[i], _arr[i]);
								_malloc.destroy(&_arr[i]);
							}
							_malloc.deallocate(_arr, tmpcap);
							for (; i < n; i++){
								_malloc.construct(&tmp[i], val);
							}
							_size = n;
							_arr = tmp;
							return ;
						}
						for (;_size != n; _size++){
							_malloc.construct(&_arr[_size], val);
						}
					}
				};

				size_type capacity() const{
					return (_capacity);
				};

				bool empty() const {
					if (_size == 0)
						return true;
					return false;
				};

				void reserve (size_type n){
					pointer tmp;
					size_type tmpcap = _capacity;
					if (n > max_size())
						throw std::length_error("oversize");
					if (n > _capacity){

						if (_capacity > 0){
							tmp = _malloc.allocate(n);
							_capacity = n;
						}
						else{
							tmp = _malloc.allocate(n);
							_capacity = n;
						}
						for (size_type i = 0; i < _size; i++){
							_malloc.construct(&tmp[i], _arr[i]);
							_malloc.destroy(&_arr[i]);
						}
						_malloc.deallocate(_arr, tmpcap);
						_arr = tmp;
					}
					
				};



//Modifiers
				template <class InputIterator> 
				void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
					for (size_type i = 0; i < _size; i++){
						_malloc.destroy(&_arr[i]);
					}
					_size = 0;

					InputIterator it(first);
					size_type	dif = 0;
					while (it != last)
					{
						dif++;
						it++;
					}
					if (dif > _capacity){
						_malloc.deallocate(_arr, _capacity);
						_capacity = dif;
						_arr = _malloc.allocate(_capacity);
					}
					for (it = first; it != last; it++){
						push_back(*it);
					}
				};

				void assign (size_type n, const value_type& val){
					for (size_type i = 0; i < _size; i++){
						_malloc.destroy(&_arr[i]);
					}
					_size = 0;
					if (n > _capacity){
						_malloc.deallocate(_arr, _capacity);
						_capacity = n;
						_arr = _malloc.allocate(_capacity);
					}
					for (; n != 0; n--){
						push_back(val);
					}
				};

				void push_back (const value_type& val){
					pointer tmp;
					size_type tmpcap = _capacity;
					if (_capacity == _size){
						if (_size > 0){
							tmp = _malloc.allocate(_size * 2);
							_capacity = _size * 2;
						}
						else{
							tmp = _malloc.allocate(1);
							_capacity = 1;
						}
						for (size_type i = 0; i < _size; i++){
							_malloc.construct(&tmp[i], _arr[i]);
							_malloc.destroy(&_arr[i]);
						}
						_malloc.deallocate(_arr, tmpcap);
						_arr = tmp;
					}
					_malloc.construct(&_arr[_size], val);
					_size++;
				};

				void pop_back(){
					if (_size > 0){
						_malloc.destroy(&_arr[_size - 1]);
						_size--;
					}
				};

				iterator insert (iterator position, const value_type& val){

					if (position == end()){
						push_back(val);
						return end() - 1;
					}

					size_type	tmp1 = position - begin();

					pointer tmp;
					size_type tmpcap = _capacity;
					if (_capacity < _size + 1){
						if (_size > 0){
							tmp = _malloc.allocate(_size * 2);
							_capacity = _size * 2;
						}
						else{
							tmp = _malloc.allocate(3);
							_capacity = 3;
						}
						for (size_type i = 0; i < _size; i++){
							_malloc.construct(&tmp[i], _arr[i]);
							_malloc.destroy(&_arr[i]);
						}
						_malloc.deallocate(_arr, tmpcap);
						_arr = tmp;
					}
					size_type i = _size;
					for (; i > tmp1; i--){
						_malloc.construct(&_arr[i], _arr[i - 1]);
						_malloc.destroy(&_arr[i - 1]);
					}
					_malloc.construct(&_arr[i], val);
					_size++;
					return iterator(_arr + tmp1);
				};

				void insert (iterator position, size_type n, const value_type& val){
						for (size_type i = 0; i != n; i++){
							position = insert(position, val);
						}
				};

				template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
					InputIterator it(first);
					size_type	dif = 0;
					while (it != last)
					{
						dif++;
						it++;
					}
					pointer tmp;
					size_type	tmp1 = position - begin();
					size_type tmpcap = _capacity;
					if (_capacity < _size + dif){
						if (_size > 0){
							tmp = _malloc.allocate((_size + dif) * 2);
							_capacity = (_size + dif) * 2;
						}
						else{
							tmp = _malloc.allocate(3 + dif);
							_capacity = 3 + dif;
						}
						for (size_type i = 0; i < _size; i++){
							_malloc.construct(&tmp[i], _arr[i]);
							_malloc.destroy(&_arr[i]);
						}
						_malloc.deallocate(_arr, tmpcap);
						_arr = tmp;
					}

					for (size_type i = _size + dif; i > tmp1 + dif ; i--){
						_malloc.construct(&_arr[i - 1], _arr[i - dif - 1]);
						_malloc.destroy(&_arr[i - dif - 1]);
					}
					
					for (size_type i = tmp1; i < tmp1 + dif ; i++){
						_malloc.construct(&_arr[i], *(first++));
						_size++;
					}

				};


				iterator erase (iterator position){
					if (position == end()){
						pop_back();
						return end();
					}

					size_type	tmp1 = position - begin();

				

					for (size_type i = tmp1; i < _size - 1 ; i++){
						_malloc.construct(&_arr[i], _arr[i + 1]);
						_malloc.destroy(&_arr[i + 1]);
					}
					_size--;
					return position;
				};

				iterator erase (iterator first, iterator last){

					size_type	start = first - begin();
					size_type	range = last - first;


					size_type i = start;

					for (; i < _size - range; i++){
						_malloc.destroy(&_arr[i]);
						_malloc.construct(&_arr[i], _arr[i + range]);
					};
					for (;i < _size; i++){
						_malloc.destroy(&_arr[i]);
					}
					_size -= range;
					return iterator(_arr + start);
				};

				void swap (vector& x){
					size_type		size;
					size_type		capacity;
					pointer 		arr;
					allocator_type	malloc;

					size = x._size;
					capacity = x._capacity;
					arr = x._arr;
					malloc = x._malloc;

					x._size = _size;
					x._capacity = _capacity;
					x._arr = _arr;
					x._malloc = _malloc;

					_size = size;
					_arr = arr;
					_capacity = capacity;
					_malloc = malloc;
				};

				void clear(){
					for (size_type i = 0; i < _size; i++){
						_malloc.destroy(&_arr[i]);
					}
					_size = 0;
				};

// ACCESSORS
				reference operator[] (size_type n){
					return _arr[n];
				};

				const_reference operator[] (size_type n) const {
					return _arr[n];
				};

				reference at (size_type n){
					if (n >= _size)
						throw std::out_of_range ("out of range");
					return _arr[n];
				};

				const_reference at (size_type n) const {
					if (n >= _size)
						throw std::out_of_range ("out of range");
					return _arr[n];
				};

				reference front(){
					return (_arr[0]);
				};

				const_reference front() const{
					return (_arr[0]);
				};

				reference back(){
					return (_arr[_size - 1]);
				};

				const_reference back() const{
					return (_arr[_size - 1]);
				};

// NON MEMBER BUT MEMBER BUT FRIEND
				


				friend bool operator== (const vector& lhs, const vector& rhs){
					if (lhs.size() != rhs.size())
						return false;
					size_type i = 0;
					size_type min = lhs.size();
					while (i < min) {
						if (lhs[i] != rhs[i])
							return false;
						++i;
					}
					return true;
					// iterator	l = lhs.begin();
					// iterator	r = rhs.begin();
					// for (; l != lhs.end() && r != rhs.end();l++, r++){
					// 	if ((*l) != (*r))
					// 		return false;
					// }
					// if (l == lhs.end() && r == rhs.end())
					// 	return true;
					// return false;
				};
					
				friend bool operator!= (const vector& lhs, const vector& rhs){
					return (!(lhs == rhs));
				};
					
				friend bool operator<  (const vector& lhs, const vector& rhs){
					
					return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
					
					// iterator	l = lhs.begin();
					// iterator	r = rhs.begin();
					// for (; l != lhs.end() && r != rhs.end();l++, r++){
					// 	if ((*l) != (*r))
					// 		return ((*l) < (*r));
					// }
					// if (l == lhs.end() && r != rhs.end())
					// 	return true;
					// return false;
				};
					
				friend bool operator<= (const vector& lhs, const vector& rhs){
					return (!(rhs < lhs));
				};
					
				friend bool operator>  (const vector& lhs, const vector& rhs){
					return (rhs < lhs);
				};
					
				friend bool operator>= (const vector& lhs, const vector& rhs){
					return (!(lhs < rhs));
				};




	};

	template <class T>
	void swap (vector<T>& x, vector<T>& y){
		y.swap(x);
};
	};