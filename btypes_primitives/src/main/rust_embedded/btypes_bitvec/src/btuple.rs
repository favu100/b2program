

pub trait BTuple<L, R> {
    fn projection1(self) -> L;
    fn projection2(self) -> R;
}

impl<L, R> BTuple<L, R> for (L, R)
where L: Clone,
      R: Clone {
    fn projection1(self) -> L { self.0.clone() }
    fn projection2(self) -> R { self.1.clone() }
}

//TODO: Somehow impl SetItem