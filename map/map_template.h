#ifndef MAP_TEMPLATE_H
#define MAP_TEMPLATE_H
#include<vector>
#include <iostream>


template <typename KeyT, typename ValueT>
class map_template
{
public:

	void Add(KeyT key, ValueT value)
	{
		m_keys.push_back(key);
		m_values.push_back(value);
	}
	ValueT* Find(KeyT key)
	{
		
		
		for(size_t k=0;k<m_keys.size();k++)
		{
			if (m_keys[k] = key)
			{
				return &(m_values[k]);
			}
		}
		return nullptr;
	}

	friend std::ostream& operator<< (std::ostream& ostr, const map_template<KeyT, ValueT>& map_temp)
	{
		for (size_t k = 0; k < map_temp.m_keys.size(); k++)
		{
			ostr << map_temp.m_keys[k] << "  " << map_temp.m_values[k] << "\n";
		}
		return ostr;
	}

private:
	std::vector<KeyT> m_keys;
	std::vector<ValueT> m_values;
};

#endif // !MAP_TEMPLATE_H