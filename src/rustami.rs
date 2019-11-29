// rustami.rs

const N_MAX: i32 = 100000000;

fn tatami(s: i32) -> i32 {
    let mut v: Vec<u8> = vec![0; N_MAX as usize];
    let n_max_sqrt: i32 = (N_MAX as f64).sqrt() as i32;

    for i in 0..n_max_sqrt {
        let mut k2: i32;
        let mut k3: i32;
        let mut k: i32 = 1;
        
        loop {
            k2 = (k * i) + k + 2;
            k3 = ((k + 1) * i) - k - 3;
            if k2 > k3 {
                break;
            } 
            if (i * k2) >= N_MAX {
                break;
            }
            for j in k2..=k3 {
                if (((i & j & 1) > 0)) || (i * j >= N_MAX) {
                    continue;
                }
                v[(i * j) as usize] += 1;
            }
            k += 1;
        }
    }
    for i in 0..N_MAX {
        if v[i as usize] == s as u8 {
            return i;
        }
    }
    assert!(false, "Should never get here!");
    s
}

fn main() {
    println!("The smallest room size s for which T(s) = 200 is {}", tatami(200));
}
