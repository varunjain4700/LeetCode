/*
 *Below is the interface for Iterator, which is already defined for you.
 ***DO NOT**modify the interface for Iterator.
 *
 *class Iterator {
 *		struct Data;
 *		Data* data;
 *public:
 *		Iterator(const vector<int>& nums);
 *		Iterator(const Iterator& iter);
 *
 *		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator: public Iterator
{
    public: 
    int next_val;
    bool hasnext_it = 0;
    PeekingIterator(const vector<int> &nums): Iterator(nums)
    {
       	// Initialize any member here.
       	// **DO NOT**save a copy of nums and manipulate it directly.
       	// You should only use the Iterator interface methods.
        hasnext_it = Iterator::hasNext();
        if (hasnext_it)
            next_val = Iterator::next();
    }

   	// Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return next_val;
    }

   	// hasNext() and next() should behave the same as in the Iterator interface.
   	// Override them if needed.
    int next()
    {
        int currNext_val = next_val;
        hasnext_it = Iterator::hasNext();
        if (hasnext_it)
            next_val = Iterator::next();
        return currNext_val;
    }

    bool hasNext() const
    {
        if (hasnext_it)
            return true;
        return false;
    }
};