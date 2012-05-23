//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_list.h
 * @brief		iris unit test list 構造 ファイル
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2011-2012, Takazumi Shirayanagi\n
 * The new BSD License is applied to this software.
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_list_H_CB5AECEA_6147_4a89_BB97_236338CA177E_
#define INCG_IRIS_iutest_list_H_CB5AECEA_6147_4a89_BB97_236338CA177E_

//======================================================================
// include
#ifdef _IUTEST_DEBUG
#include <assert.h>
#endif

namespace iutest {
namespace detail
{

//======================================================================
// class
/**
  * @internal
  * @brief	リストノード
*/
template<typename TN>
class iu_list_node
{
	typedef TN	*value_ptr;
	typedef iu_list_node<TN>	_Myt;
public:
	value_ptr	next;
	value_ptr	prev;

protected:
	iu_list_node(void) : next(NULL)
		, prev(NULL)
	{}
};

/**
  * @internal
  * @brief	リストイテレータ
*/
template<typename NODE>
class iu_list_iterator
{
	typedef iu_list_iterator<NODE>	_Myt;
public:
	typedef NODE		value_type;
	typedef NODE		*value_ptr;
	typedef value_ptr	pointer;
	typedef value_type&	reference;
	typedef int			distance_type;
	typedef int			difference_type;
public:
	value_ptr	m_node;
public:
	iu_list_iterator(value_ptr p=NULL) : m_node(p) {}
	iu_list_iterator(const _Myt& rhs) : m_node(rhs.m_node) {}

public:
	int			operator == (const _Myt& it)		const { return this->m_node == it.m_node; }
	int			operator != (const _Myt& it)		const { return this->m_node != it.m_node; }

	_Myt&		operator ++ (void)	{ m_node = m_node->next; return *this; }
	_Myt&		operator -- (void)	{ m_node = m_node->prev; return *this; }
	value_ptr	operator -> (void)	{ return m_node; }
	value_ptr	operator *  (void)	{ return m_node; }
	value_ptr	ptr(void)	const	{ return m_node; }

	_Myt		operator + (int n)
	{
		if( n == 0 ) return *this;
		if( n > 0 )
		{
			return this->operator +(static_cast<unsigned int>(n));
		}
		_Myt ret(*this);
		n = -n;
		for( int i=0; i < n && ret.m_node != NULL; ++i )
		{
			ret.m_node = ret.m_node->prev;
		}
		return ret;
	}

	_Myt		operator + (unsigned int n)
	{
		_Myt ret(*this);
		for( unsigned int i=0; i < n && ret.m_node != NULL; ++i )
		{
			ret.m_node = ret.m_node->next;
		}
		return ret;
	}
};

/**
 * @internal
 * @brief	リストクラス
 * @deprecated stl に変えたほうがいいかも、保守するのがメンドイ	
*/
template<typename NODE>
class iu_list
{
	typedef NODE	*node_ptr;
	typedef iu_list<NODE>	_Myt;
protected:
	node_ptr	m_node;

public:
	typedef iu_list_iterator<NODE>	iterator;
public:
	iu_list(node_ptr p=NULL) : m_node(p) {}

public:
	// リストの総数取得
	unsigned int count(void) const
	{
		unsigned int cnt = 0;
		node_ptr cur = m_node;
		while(cur != NULL)
		{
			++cnt;
			cur = cur->next;
		}
		return cnt;
	}
public:
	// ソートして挿入
	void		sort_insert(node_ptr p)
	{
		if( m_node == NULL )
		{
			m_node = p;
			return;
		}

		if( *p < *m_node )
		{
			// 入れ替え
			node_ptr next = m_node;
			m_node = p;
			p->next = next;
			next->prev = p;
		}
		else
		{
			node_ptr prev = m_node;
			node_ptr cur = m_node->next;
			while(cur != NULL)
			{
				if( *p < *cur )
				{
					break;
				}
				prev = cur;
				cur = prev->next;
			}
			prev->next = p;
			p->prev = prev;
			p->next = cur;
			if( cur != NULL )
			{
				cur->prev = p;
			}
		}
	}
	// 追加
	void		push_back(node_ptr p)
	{
		if( m_node == NULL ) 
		{
			m_node = p;
			return;
		}
		node_ptr prev = m_node;
		node_ptr cur = m_node->next;
		while(cur != NULL)
		{
			if( prev == p ) return;
			prev = cur;
			cur = prev->next;
		}
		prev->next = p;
		p->prev = prev;
	}
	// 削除
	void		erase(node_ptr p)
	{
		if(m_node == NULL) return;
		if( p->prev == NULL )
		{
			m_node = p->next;
			if( m_node != NULL )
			{
				m_node->prev = NULL;
			}
		}
		else
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
		p->prev = p->next = NULL;
	}

public:
	/**
	 * @brief	シャッフル
	 * @tparam	F = 比較オブジェクト
	*/
	template<typename F>
	void	shuffle(F& r)
	{
		for( unsigned int i=2, n=count(); i<n; ++i )
		{
			swap(begin() + (i-2), begin() + r(i) % i );
		}
	}

public:
	void		swap(iterator a, iterator b)
	{
		if( a == b ) return;
		if( a.ptr() == m_node ) m_node = b.ptr();
		else if( b.ptr() == m_node ) m_node = a.ptr();

		if( a->next == b.ptr() )
		{
			a->next = b->next;
			b->next = a.ptr();
			b->prev = a->prev;
			a->prev = b.ptr();
			if( a->next != NULL ) a->next->prev = a.ptr();
			if( b->prev != NULL ) b->prev->next = b.ptr();
		}
		else if( a->prev == b.ptr() )
		{
			b->next = a->next;
			a->next = b.ptr();
			a->prev = b->prev;
			b->prev = a.ptr();
			if( b->next != NULL ) b->next->prev = b.ptr();
			if( a->prev != NULL ) a->prev->next = a.ptr();
		}
		else
		{
			node_ptr tmp = a->next;
			a->next = b->next;
			b->next = tmp;
			tmp = a->prev;
			a->prev = b->prev;
			b->prev = tmp;
			if( a->next != NULL ) a->next->prev = a.ptr();
			if( b->next != NULL ) b->next->prev = b.ptr();
			if( a->prev != NULL ) a->prev->next = a.ptr();
			if( b->prev != NULL ) b->prev->next = b.ptr();
		}
	}

public:
	iterator	begin(void) const
	{
		return m_node;
	}
	iterator	end(void) const
	{
		return iterator(NULL);
	}

public:
	struct EqualOp
	{
		template<typename T>
		bool	operator () (const T* lhs, const T* rhs)	const	{ return *lhs == *rhs; }
	};
public:
	template<typename FUNC>
	node_ptr	find(node_ptr p, FUNC& f)
	{
		node_ptr cur = m_node;
		while( cur != NULL )
		{
			if( f(cur, p) ) return cur;
			cur = cur->next;
		}
		return NULL;
	}
	template<typename FUNC>
	node_ptr	find(FUNC& f)
	{
		node_ptr cur = m_node;
		while( cur != NULL )
		{
			if( f(cur) ) return cur;
			cur = cur->next;
		}
		return NULL;
	}

public:
	node_ptr	operator -> (void)	{ return m_node; }
	node_ptr	operator &	(void)	{ return m_node; }
	NODE&		operator *  (void)	{ return *m_node; }

	node_ptr	operator [] (int index) const
	{
		node_ptr cur = m_node;
		for( int i=0; i < index; ++i )
		{
			cur = cur->next;
			if( cur == NULL ) break;
		}
		return cur;
	}

	bool		operator == (node_ptr p)	const	{ return m_node == p; }
	bool		operator != (node_ptr p)	const	{ return m_node != p; }

private:
#ifdef _IUTEST_DEBUG
	// ノードの状態チェック
	bool		check_node(void)
	{
		if( m_node == NULL ) return true;
		node_ptr prev = m_node;
		node_ptr curr = prev->next;
		while( curr != NULL )
		{
			assert( prev->next == curr );
			assert( curr->prev == prev );
			prev = curr;
			curr = prev->next;
		}
		return true;
	}
#endif
};

}	// end of namespace detail
}	// end of namespace iutest


#endif
