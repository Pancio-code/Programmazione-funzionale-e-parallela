class MioVector[T](v: Vector[T]) {
	def isMappedFrom[M](v1: Vector[M],f: T => M):Boolean = {
		if(v.length != v1.length) false
		else v.zip(v1).forall(t => f(t._1) == t._2)
	}
}

object E2 {
	implicit def Vector2MioVector[T](v: Vector[T]) = new MioVector(v)
}
