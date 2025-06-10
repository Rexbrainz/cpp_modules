/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudaniel <sudaniel@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:43:03 by sudaniel          #+#    #+#             */
/*   Updated: 2025/06/09 11:56:45 by sudaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array() : m_array(new T[m_size]) {}

template<typename T>
Array<T>::Array(unsigned int n) :  m_size(n), m_array(new T[n]) {}

template<typename T>
Array<T>::~Array()
{
    delete[] m_array;
}

template<typename T>
Array<T>::Array(const Array& other) : Array(other.size())
{
    for (size_type i = 0; i < m_size; ++i)
        m_array[i] = other.m_array[i];
}

template<typename T>
Array<T>&  Array<T>::operator=(const Array& rhs)
{
    if (this != &rhs)
    {
        delete[] m_array;
        m_size = rhs.size();
        m_array = new T[m_size];
        for (size_type i = 0; i < m_size; ++i)
            m_array[i] = rhs.m_array[i];
    }
    return (*this);
}

template<typename T>
const T&    Array<T>::operator[](size_type index) const
{
    verifyIndex(index);
    return (m_array[index]);
}

template<typename T>
T&  Array<T>::operator[](size_type index)
{
    verifyIndex(index);
    return (m_array[index]);
}

template<typename T>
typename Array<T>::size_type   Array<T>::size() const
{
    return (m_size);
}

template<typename T>
void    Array<T>::verifyIndex(size_type index) const 
{
    if (index >= size())
        throw std::out_of_range("out of range index");
}
                                                     
