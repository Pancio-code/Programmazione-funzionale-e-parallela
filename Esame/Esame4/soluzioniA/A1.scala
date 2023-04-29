object A1 {
    def select(cars:List[Car]) =
        cars.groupBy(c=>c.year)
            .toList.map(
                 p => (p._1, p._2.map(_.owner)
                                 .reduce((a,b)=>if (a.age < b.age) a else b)
                                 .name
                      )
            )
}
