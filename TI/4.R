cat("\014")
library(prob)
L <- 5;

cat("-=( ЛАБА 4, ВАРІАНТ", L,")=-\n")
cat("\n")


cat("-=( 1 )=-\n")
  pdiscrete <- function(x, xk, pk){
    ind <- which(xk < x)
    return(sum(pk[ind]))
  }
  xk <- c(5, 6, 6.6, 7, 7.7, 8)
  pk <- c(0.3, 0.15, 0.15, 0.1, 0.25, 0.05)
  p <- pdiscrete(5, xk, pk)
  
  x <- xk
  y <- c(0, cumsum(pk))
  
  myFun <- stepfun(x, y, f=1, right = TRUE)
  plot.stepfun(myFun, xlab="x", ylab="F(x)",
               main = "ФункціЯ розподілу дискретної випадкової величини",
               verticals=FALSE, pch=16)
  cat("    ", "Вивід відсутній. Див. графік\n")
  cat("\n")


cat("-=( 2 )=-\n")
  n <- 28
  k <- 0:n
  p <- 0.14
  l <- 0.8
  N <- 140
  M <- 120
  a <- 2
  b <- 5
  
  cat("  ", "Біномний розподіл (червоний)", "\n");
    B <- dbinom(k, n, p)
    plot(k, B, col="red", type="b", pch=16, ylim=range(c(B, G, P, R)), xlim=range(k))
    equalsB <- sum(B) == 1
    maxKB <- k[which(B == max(B))]
    inrangeB <- pbinom(b, n, p) - pbinom(a-1, n, p)
    cat("    ", "SUM == 1:   ", equalsB, "\n");
    cat("    ", "Kmax:        ", maxKB, "\n");
    cat("    ", "В проміжок:  ", inrangeB, "\n");
    cat("\n");
  
  cat("  ", "Розподіл Пуассона (синій)", "\n");
    P <- dpois(k, l)
    lines(k, P, col="blue", type="b", pch=16)
    equalsP <- sum(P) == 1
    maxKP <- k[which(P == max(P))]
    inrangeP <- ppois(b, l) - ppois(a-1, l)
    cat("    ", "SUM == 1:   ", equalsP, "\n");
    cat("    ", "Kmax:        ", maxKP, "\n");
    cat("    ", "В проміжок:  ", inrangeP, "\n");
    cat("\n");
  
  cat("  ", "Геометричний розподіл (зелений)", "\n");
    G <- dgeom(k, p)
    lines(k, G, col="green", type="b", pch=16)
    equalsG <- sum(G) == 1
    maxKG <- k[which(G == max(G))]
    inrangeG <- pgeom(b, p) - pgeom(a-1, p)
    cat("    ", "SUM == 1:   ", equalsG, "\n");
    cat("    ", "Kmax:        ", maxKG, "\n");
    cat("    ", "В проміжок:  ", inrangeG, "\n");
    cat("\n");
  
  cat("  ", "Гіпергеометричний розподіл (пурпурний)", "\n");
    R <- dhyper(k, M, N-M, n)
    lines(k, R, col="magenta", type="b", pch=16)
    equalsR <- sum(R) == 1
    maxKR <- k[which(R == max(R))]
    inrangeR <- phyper(b, M, N-M, n) - phyper(a-1, M, N-M, n)
    cat("    ", "SUM == 1:   ", equalsR, "\n");
    cat("    ", "Kmax:        ", maxKR, "\n");
    cat("    ", "В проміжок:  ", inrangeR, "\n");
    cat("\n");
