
// COS30008, Final Exam, 2023

#pragma once

#include <memory>
#include <cassert>
#include <algorithm>

template<typename T>
class TernaryTree
{
public:
    
    using Node = std::unique_ptr<TernaryTree>;

public:

    TernaryTree(const T& aKey = T{}) noexcept:
        fKey(aKey)
    {}

    TernaryTree( T&& aKey ) noexcept:
        fKey(std::move(aKey))
    {}

    template<typename... Args>
    static Node makeNode(Args&&... args)
    {
        return Node(new TernaryTree<T>(std::forward<Args>(args)...));
    }

    const T& operator*() const noexcept
    {
        return fKey;
    }

    TernaryTree& operator[](size_t aIndex) const
    {
        assert(aIndex < 3);
        assert(fNodes[aIndex]);

        return *fNodes[aIndex];
    }

    void add(size_t aIndex, Node& aNode)
    {
        assert(aIndex < 3);
        assert(!fNodes[aIndex]);

        fNodes[aIndex] = std::move(aNode);
    }

    Node remove(size_t aIndex)
    {
        assert(aIndex < 3);
        assert(fNodes[aIndex]);
        Node lTemp = std::move(fNodes[aIndex]);
        fNodes[aIndex] = nullptr;
        return lTemp;
    }

    bool leaf() const noexcept
    {
        for (const auto& node : fNodes) {
            if (node) return false;
        }
        return true;
    }

    size_t height() const noexcept
    {
        size_t max_height = 0;
        for (const auto& node : fNodes) {
            if (node) {
                max_height = std::max(max_height, 1 + node->height());
            }
        }
        return max_height;
    }

private:

    T fKey;
    Node fNodes[3];
};

