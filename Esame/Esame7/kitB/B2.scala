 object B2 {
    def maxSubSeq[T](l:List[T], p:T => Boolean):List[T] = {
        ( 0 to l.length ).toList.map( e => l.splitAt(e)._2).map( e => e.takeWhile(p)).maxBy( _.length)
    }
}
