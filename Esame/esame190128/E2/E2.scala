object E2 {
	def extract[T](l:Seq[T], idx:Set[Int]):Seq[T] = {
		(0 to l.size-1).filter( i => idx.contains(i)).map( i => l(i)).toSeq
	}
}
