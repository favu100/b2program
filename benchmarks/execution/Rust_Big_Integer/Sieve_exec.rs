mod Sieve;

fn main(){
    let mut sieve = Sieve::Sieve::new();
    println!("{}", sieve.ComputeNumberOfPrimes());
}