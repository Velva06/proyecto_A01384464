 Unidad
------------------------------
- nombre: string
- saludMax: int
- salud: int
- ataque: int
- cargaUltima: int
- cargaMaxima: int- vivo: bool
------------------------------
+ Unidad(n: string, hp: int, atk: int, cargaUlt: int)
+ virtual ~Unidad()
+ virtual void usarUltima(objetivo: Unidad&) = 0
+ virtual void atacar(objetivo: Unidad&)
+ void recargarUltima()
+ void mostrarInfo()
+ void mostrarInfo(k: int)
+ void intentarUsarUltima(objetivo: Unidad&)
+ virtual void recibirDanio(danio: int)
+ bool estaVivo(): bool
+ getNombre(): string
+ getSalud(): int
+ getSaludMax(): int
+ getCargaUltima(): int
+ getCargaMaxima(): int

     ▲
     │
────────────────────────────────────────────────────────────
│           │            │         │         │
Guerrero  Arquero      Mago     Tanque    Asesino
────────  ───────      ─────     ──────    ───────
+ usarUltima(objetivo: Unidad&)
+ mostrarInfo()
(heredan todo de Unidad)

────────────────────────────────────────────────────────────

<<funciones globales>>
------------------------------
+ crearPersonaje(tipo: int, esEnemigo: bool): Unidad*
+ elegirEquipoJugador(): vector<Unidad*>
+ generarEquipoEnemigo(): vector<Unidad*>
+ combate(jugador: vector<Unidad*>, enemigo: vector<Unidad*>)
+ mostrarEstado(u: Unidad*)
+ mostrarOpciones()
+ operator<<(os: ostream&, u: const Unidad&): ostream&
────────────────────────────────────────────────────────────

<<main>>
------------------------------
main()
- Llama a: elegirEquipoJugador(), generarEquipoEnemigo(), combate()

