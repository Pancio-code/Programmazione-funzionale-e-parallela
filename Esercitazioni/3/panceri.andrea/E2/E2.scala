object E2 {
    def getModel(n:Int):List[Shape] =
        (1 to n).toList.map(i=>Circle(0.5*i/n,0.5*i/n,0.5*i/n))
}
