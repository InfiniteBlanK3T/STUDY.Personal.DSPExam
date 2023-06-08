
// COS30008, Final Exam, 2023

#include "DSPStringIterator.h"
#include <cassert>

DSPStringIterator::DSPStringIterator( const DSPString& aCollection ) :
	fCollection( std::make_shared<DSPString>( aCollection ) ),
	fIndex( 0 )
{}

char DSPStringIterator::operator*() const noexcept
{
	// 4A
	return (*fCollection)[fIndex];
}

DSPStringIterator& DSPStringIterator::operator++() noexcept
{
	// 4B
	if (fIndex < fCollection->size())
	{
		++fIndex;
	}
	return *this;
}

DSPStringIterator DSPStringIterator::operator++( int ) noexcept
{
	DSPStringIterator old = *this;

	++(*this);

	return old;
}

DSPStringIterator& DSPStringIterator::operator--() noexcept
{
	// 4C
	if (fIndex > 0)
	{
		--fIndex;
	}
	return *this;
}

DSPStringIterator DSPStringIterator::operator--( int ) noexcept
{
	DSPStringIterator old = *this;

	--(*this);

	return old;
}

bool DSPStringIterator::operator==( const DSPStringIterator& aOther ) const noexcept
{
	// 4D
	return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool DSPStringIterator::operator!=( const DSPStringIterator& aOther ) const noexcept
{
	return !(*this == aOther);
}

DSPStringIterator DSPStringIterator::begin() const noexcept
{
	// 4E
	DSPStringIterator iter = *this;
	iter.fIndex = 0;
	return iter;
}

DSPStringIterator DSPStringIterator::end() const noexcept
{
	// 4F
	DSPStringIterator iter = *this;
	iter.fIndex = fCollection->size();
	return iter;
}

DSPStringIterator DSPStringIterator::rbegin() const noexcept
{
	// 4G
	DSPStringIterator iter = *this;
	iter.fIndex = fCollection->size() - 1;
	return iter;
}

DSPStringIterator DSPStringIterator::rend() const noexcept
{
	// 4H
	DSPStringIterator iter = *this;
	iter.fIndex = 0;
	return iter;
}

