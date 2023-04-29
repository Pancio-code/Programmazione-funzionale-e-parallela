object A1 {
	implicit def SetToMySet(s : Set[Int]) = MioSet(s)
}

case class MioSet(s : Set[Int]) {
	def +(s1 : Set[Int]) : Set[Int] = s.union(s1)
	def -(s1 : Set[Int]) : Set[Int] = s.diff(s1)
}
