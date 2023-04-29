case class Film(id:Int, titolo:String, anno:Int)
case class Regista(id:Int, nome:String)
case class DirettoDa(idFilm:Int, idRegista:Int)

case class DB(film:List[Film], registi:List[Regista], regie:List[DirettoDa]) {
    def registiConFilm(p:Film=>Boolean):List[Regista] = {
        registi.filter(r => regie.exists( d => r.id == d.idRegista && film.exists( f => f.id == d.idFilm && p(f))))
    }
}
