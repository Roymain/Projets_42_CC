#pragma once

#include "IteratorTraits.hpp"

namespace ft {
	template <class Iterator> class reverse_iterator {
		public: 
    		typedef typename ft::iterator_traits<Iterator>::difference_type  	difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type  		value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer  			pointer;
			typedef typename ft::iterator_traits<Iterator>::reference  			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category  	iterator_category;
			typedef Iterator					  							iterator_type;
		private:
			iterator_type	_it;
		
		public:
			reverse_iterator() : _it(iterator_type()){};

			explicit reverse_iterator (iterator_type it) : _it(it){};
	
			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it.base()){};


			reverse_iterator&	operator=(const reverse_iterator& rhs) {
			if (this != &rhs)
				this->_it = rhs._it;
			return (*this);
			}





			iterator_type base() const{
				return (_it);
			};

			reference operator*() const{
				return *(--iterator_type(_it));
			};

			reverse_iterator operator+ (difference_type n) const{
				return reverse_iterator(_it - n);
			};
			



			reverse_iterator& operator++ ( void ) {
				--_it;
				return (*this);
			};
			
			reverse_iterator operator++ (int) {
				reverse_iterator temp = *this;
  				++(*this);
				return temp;
			};
			

			
			reverse_iterator& operator+= (difference_type n) {
				_it -= n;
				return *this;
			};
			
			reverse_iterator operator- (difference_type n) {
				return reverse_iterator(_it + n);
			};
			



			reverse_iterator& operator-- ( void ) {
				++_it;
				return (*this);
			};
			
			reverse_iterator operator-- (int) {
				reverse_iterator temp = *this;
  				--(*this);
				return temp;
			};
			


			reverse_iterator& operator-= (difference_type n){
				_it += n;
				return *this;
			};

			pointer operator->() const {
  				return &(operator*());
			}

			reference operator[] (const difference_type n) const{
				reverse_iterator tmp = *this;
				tmp += n;
				return *(tmp);
			};


		template <class It1, class It2>	
		friend bool operator== (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() == rhs.base());
		}
		template <class It1, class It2>	
		friend bool operator!= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() != rhs.base());
		}
		template <class It1, class It2>	
		friend bool operator<  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() > rhs.base());
		}
		template <class It1, class It2>	
		friend bool operator<= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() >= rhs.base());
		}
		template <class It1, class It2>	
		friend bool operator>  (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() < rhs.base());
		}
		template <class It1, class It2>	
		friend bool operator>= (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
			return (lhs.base() <= rhs.base());
		}
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it){
		return (rev_it + n);
	};
	
	template <class It1, class It2>
	typename reverse_iterator<It1>::difference_type operator- (const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs){
		return (rhs.base() - lhs.base());
	};
}