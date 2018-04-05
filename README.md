# tensor

Speculative work towards a robust tensor interface. The entire interface is based around accessing references to the underlying array data, no consideration for slicing or subviews or anything had been made yet. 

Work was discontinued on this before moving from a very basic dense implementation (densor.cc/h) to at least one sparse implementation because I didn't like the complexity of the indexed data retreival functionality for dense tensors. 
Since only the order and underlying type of the tensor were compile-time constants, and not the bounds of any of the tensor dimensions, no non-iterative method of indexing is really available. 
For small tensor orders the indexing loop would probably be unrolled and the (relatively untested) indexing operation wouldn't be terrible, but still not uncomplicated.

If I reworked the tempalte interface to include bounds of dimensionality as variadic template parameters as well as the indexing types the indexing function could be largely computed at compile-time (maybe, more thought would need to go into it).

However that would only speed up the access for tensors with bounds known at compile-time, which would provide a lot of utility, but a version without compile-time bounds would be warranted as well to handle dynamic tensor construction at runtime for far more general utility.
