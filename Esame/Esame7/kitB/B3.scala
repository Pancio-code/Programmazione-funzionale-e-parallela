object B3 {
    def test[T](l1:List[T], l2:List[T]):Boolean = {
        !l1.exists( e => !l2.contains(e)) || !l2.exists( e => !l1.contains(e))
    }
}
