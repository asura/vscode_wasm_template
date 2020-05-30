#ifndef PATH_PLANNING_H
#define PATH_PLANNING_H

#include "config.h"
#include "optional.h"

#include <deque>
#include <functional>  // reference_wrapper
#include <queue>       // priority_queue
#include <unordered_map>

/**
 * 重複検出のため生成済み・展開済みノードを保持する
 */
template <
    typename NodeKey,
    typename Cost,
    typename Hash = std::hash<NodeKey>,
    typename Pred = std::equal_to<NodeKey>>
class ClosedList
{
    std::unordered_map<NodeKey, Cost, Hash, Pred> m_data;

public:
    /// 挿入
    bool insert(const NodeKey& the_key, const Cost& the_value)
    {
        return m_data.emplace(the_key, the_value).second;
    }

    /// 検索
    optional<std::reference_wrapper<const Cost>> find(const NodeKey& the_key) const
    {
        const auto p = m_data.find(the_key);
        if (p == m_data.end())
        {
            return nullopt;
        }

        return std::cref(p->second);
    }
};

template <
    typename NodeKey,
    typename CostType>
struct KeyAndCost
{
    NodeKey key;
    CostType cost;
};

template <
    typename NodeKey,
    typename CostType>
bool operator>(
    const KeyAndCost<NodeKey, CostType>& the_lhs,
    const KeyAndCost<NodeKey, CostType>& the_rhs)
{
    return the_lhs.cost > the_rhs.cost;
}

/**
 * @brief 追加されたノード群をコストの昇順に取り出すことができるキュー
 */
template <
    typename NodeKey,
    typename CostType>
class OpenList
{
    using node_type = KeyAndCost<NodeKey, CostType>;

    /// Nodeをコスト昇順に保持するプライオリティキュー
    std::priority_queue<node_type, std::deque<node_type>, std::greater<node_type>> m_list;

public:
    void enqueue(const NodeKey& the_node_key, const CostType& the_node_cost)
    {
        m_list.push({the_node_key, the_node_cost});
    }

    optional<node_type> dequeue()
    {
        if (m_list.empty())
        {
            return nullopt;
        }

        optional<node_type> result = m_list.top();

        m_list.pop();

        return result;
    }
};

#endif  // PATH_PLANNING_H
