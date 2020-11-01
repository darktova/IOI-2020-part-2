#pragma once

/// <summary>
///		Classic binary search algorithm
///		for low -> high sorted arrays
/// </summary>
/// <typeparam name="T">
///		Type of source(array) and key to found
///	</typeparam>
/// <param name="l">
///		Left(start) index(boundary) of searching area
/// </param>
/// <param name="r">
///		Right(end) index(boundary) of searching area
/// </param>
/// <param name="src">
///		Array of sorted data
/// </param>
/// <param name="x">
///		Key to found
/// </param>
/// <returns>
///		True - key was found 
///		False - key was not found
/// </returns>
template<typename T>
bool binary_search(long long int l, long long int r, T* src, T x)
{
	// Is not one element
	while (l <= r)
	{
		// Middle index
		long long int mid = l + (r - l) / 2;

		// Key found
		if (src[mid] == x)
			return true;
		
		// Key in left part
		if (src[mid] > x)
			r = mid - 1;

		// Either in right one
		else
			l = mid + 1;
	}

	// Key was not found
	return false;
}

/// <summary>
///		Modified binary search algorithm
///		to find right-most position of key
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="l"></param>
/// <param name="r"></param>
/// <param name="src"></param>
/// <param name="x"></param>
/// <returns>
///		Right Index of key
/// </returns>
template<typename T>
long long int get_right_position(long long int l, long long int r, T* src, T x)
{
	// Result, default -1
	// if element will not found
	long long int right_index = -1;
	
	while (l <= r)
	{
		long long int mid = l + (r - l) / 2;

		// Save current left-most index
		if (src[mid] == x)
			right_index = mid;
		
		// Moving to the right-most point
		if (src[mid] <= x)
			l = mid + 1;

		// Moving to the left part
		else
			r = mid - 1;

	}

	return right_index;
}

/// <summary>
///		Modified binary search algorithm
///		to find left-most position of key
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="l"></param>
/// <param name="r"></param>
/// <param name="src"></param>
/// <param name="x"></param>
/// <returns>
///		Left Index of key
/// </returns>
template<typename T>
long long int get_left_position(long long int l, long long int r, T* src, T x)
{
	// Result, default -1
	// if element will not found
	long long int left_index = -1;
	
	while (l <= r)
	{
		// Middle point
		long long int mid = l + (r - l) / 2;

		// Save current left-most index
		if (src[mid] == x)
			left_index = mid;

		// Moving right boundary to the left-most index
		if (src[mid] >= x)
			r = mid - 1;

		// Moving to the right part
		else
			l = mid + 1;
	}

	return left_index;
}

template<typename T>
long long int findKeySeqLength(long long int l, long long int r, T* src, T x)
{
	// Exceptions
	if (!(l && r && src && (src + r)))
		return -1;
	
	long long int length = 
		get_right_position<T>(l, r, src, x) -
		get_left_position<T>(l, r, src, x);

	return (length ? ++length : 0);
}