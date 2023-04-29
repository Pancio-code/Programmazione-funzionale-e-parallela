object E2 {
    def extract[T](l:Seq[T], idx:Set[Int]):Seq[T] =
        l.zipWithIndex.filter(t => idx contains t._2).map(_._1)
}
