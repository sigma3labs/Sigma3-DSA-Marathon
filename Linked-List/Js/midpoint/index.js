// --- Directions
// Return the 'middle' node of a linked list.
// If the list has an even number of elements, return
// the node at the end of the first half of the list.
// *Do not* use a counter variable, *do not* retrieve
// the size of the list, and only iterate
// through the list one time.
// --- Example
//   const l = new LinkedList();
//   l.insertLast('a')
//   l.insertLast('b')
//   l.insertLast('c')
//   midpoint(l); // returns { data: 'b' }

function midpoint(list) {
	const size = list.size(); // checkout utils for the linkedList and size function
	let mid;
	if (size % 2 === 0) {
		mid = Math.floor(size / 2) - 1;
	} else {
		mid = Math.floor(size / 2);
	}

	const midpoint = list.getAt(mid);
	return midpoint;
}
