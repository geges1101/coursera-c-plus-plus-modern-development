#pragma once

#include <stdexcept>
#include <array>

using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) : size_(a_size){
        if(a_size > N){
            throw invalid_argument("size exceeds the limit");
        }
    }

    T& operator[](size_t index){
        return vector_[index];
    }
    const T& operator[](size_t index) const {
        return vector_[index];
    }

    auto begin(){
        return vector_.begin();
    }
    auto end(){
        return vector_.begin() + size_;
    }
    const T* begin() const {
        return vector_.begin();
    }
    const T* end() const {
        return vector_.begin() + size_;;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return N;
    }

    void PushBack(const T& value){
        if (size_ >= N) {
            throw overflow_error("Full");
        } else {
            vector_[size_++] = value;
        }
    }

    T PopBack(){
        if(Size() == 0){
            throw underflow_error("empty vector");
        }
        auto tmp = vector_[size_ - 1];
        size_ = size_ - 1;
        return tmp;
    }

private:
    array <T, N> vector_;
    size_t size_;
};
