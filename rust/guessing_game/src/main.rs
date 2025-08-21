use std::io;
use rand::Rng;
use std::cmp::Ordering;


fn main() {
    println!("Hello to my program ! its a guessing game ");
    let secret_number = rand::thread_rng().gen_range(1..=100);
    loop {
        println!("Type your guess");
        let mut guess = String::new();
        io::stdin().
            read_line(&mut guess).
            expect("some error occurred");
        let  guess: u32 = guess.trim().parse().expect("Please type a number!");

        println!("You guess the number : {guess}");

        match guess.cmp(&secret_number){
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}