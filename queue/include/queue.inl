// Copyright - 2016

#include "queue.hpp"

template <typename Data>
Queue<Data>::Queue(const int _SIZE) {
    m_SIZE = _SIZE;
    m_list = new Data[_SIZE];
}

template <typename Data>
bool Queue<Data>::enqueue(const Data &_a) {
    if (m_f == -1) {
        m_f = m_b = 0, m_list[0] = _a;
        return true;
    }

    auto final_b = (m_b + 1)%m_SIZE;

    if (final_b == m_f)  // Vector is full
        return false;

    m_list[final_b] = _a, m_b = final_b;

    return true;
}

template <typename Data>
bool Queue<Data>::dequeue(Data &_a) {
    auto queue_sz = queue_size();
    if (queue_sz == 0)  // Lista Vazia
        return false;

    if (queue_sz == 1)
        m_b = m_f = -1;
    else
        m_b = (m_b - 1)%m_SIZE;

    return true;
}

template <typename Data>
unsigned Queue<Data>::queue_size(void) {
    if (m_f == -1)  // Lista Vazia
        return 0;
    if (m_f > m_b)
        return m_SIZE - m_f + m_b + 1;
    return m_b - m_f + 1;
}
