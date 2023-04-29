object A1 {
    def select(cars:List[Car], owners:List[String]) =
        owners.map(o => cars.filter(_.owner == o).reduce((c1,c2) => if (c1.year > c2.year) c1 else c2)).map(_.model)
}
