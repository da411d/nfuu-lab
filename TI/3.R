cat("\014")
library(prob)
L <- 5;

cat("-=( ЛАБА 3, ВАРІАНТ", L,")=-\n")
cat("\n")


cat("-=( 1 )=-\n")
  n <- 5;
  p <- (L+12) / (L + 12 + L)
  probA <- dbinom(3, n, p)
  probB <- probA + dbinom(2, n, p)
  probC <- 1 - probA
  cat("Імовірність А:", probA, "\n")
  cat("Імовірність Б:", probB, "\n")
  cat("Імовірність В:", probC, "\n")
  cat("\n")


cat("-=( 2 )=-\n")
  n <- floor(200*(L+1)/L); p <- 1/40
  l <- n*p
  probA <- dbinom(5, n, p)
  aproxProbA <- dpois(5, l)
  diff1 <- abs(probA - aproxProbA)
  
  probB <- 1 - sum(dbinom(0:(L-1), n, p))
  aproxProbB <-sum(dpois(0:(L-1), l))
  diff2 <- abs(probB - aproxProbB)
  
  cat("Імовірність 1: ", probA, "\n  ", "Похибка: ", diff1, "\n\n")
  cat("Імовірність 2: ", probB, "\n  ", "Похибка: ", diff2, "\n")
  cat("\n")


cat("-=( 3 )=-\n")
  n <- 6000; k <- 1000 - (10*L)
  p <- 1/6; q <- 1 - p;
  l1 <- n*p; l2 <- n*p*q;
  
  xk <- (k - l1) / sqrt(l2)
  aproxProbA <- dnorm(xk) / sqrt(l2)
  probA <- dbinom(k, n, p)
  diff <- abs(probA - aproxProbA)
  
  cat("Бернуллі: ", probA, "\n")
  cat("Муавра-Лапласа: ", aproxProbA, "\n")
  cat("Похибка: ", diff, "\n")
  cat("\n")
  

cat("-=( 4 )=-\n")
  p <- 1 - (L+7)/(L+40); q <- 1 - p;
  n <- 120; k1 <- 85-L; k2 <- 100-L
  l1 <- n*p; l2 <- n*p*q;
  x1 <- (k1 - l1) / sqrt(l2)
  x2 <- (k2 - l1) / sqrt(l2)
  aproxProbA <- pnorm(x2, 0, 1) - pnorm(x1, 0, 1)
  probA <- sum(dbinom(k1:k2, n, p))
  diff <- abs(probA - aproxProbA)
  
  cat("Бернуллі: ", probA, "\n")
  cat("Муавра-Лапласа: ", aproxProbA, "\n")
  cat("Похибка: ", diff, "\n")
  cat("\n")
  