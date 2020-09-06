library(dplyr)
library(ggplot2)
setwd("D:/Навчання різне/Теорія Імовірностей/Теорія ймовірностей/Лабораторні роботи")
movie_body_counts <- read.csv('filmdeathcounts.csv')
head(movie_body_counts)
str(movie_body_counts)
movie_body_counts$body_per_min <-
  movie_body_counts$Body_Count/movie_body_counts$Length_Minutes

ggplot(movie_body_counts, aes(x=Body_Count))+
  geom_histogram(bins=20, color="grey", fill="lightblue")+ylab("Кількість")+xlab("Вбиті персонажі")
#bins- бункер , зберігання в засіках,перевизначений двозначно

movie_body_counts %>%
  top_n(n = 10, Body_Count) %>%
  arrange(desc(Body_Count))
#top_n() 1.number of rows to return 2.Variable to use for ordering
#Arrange Rows By Variables
#arrange - сортування, desc - спадаючий
#порядок
#Use desc() to sort a variable in descending order.
movie_body_counts %>%
  top_n(n = 10, body_per_min) %>%
  arrange(desc(body_per_min))

ggplot(movie_body_counts, aes(x=IMDB_Rating)) +
  geom_histogram(bins=10, color="grey", fill="lightgreen")+ylab("Кількість фільмів")

imdb_mean<-mean(movie_body_counts$IMDB_Rating)
imdb_mean1<-movie_body_counts%>%summarise(mean(IMDB_Rating))

imdb_sd<-movie_body_counts%>%summarise(mean(IMDB_Rating),sd(IMDB_Rating))
imdb_sd1<-sd(movie_body_counts$IMDB_Rating)

set.seed(900)
imdb_simulation<-rnorm(n=nrow(movie_body_counts), mean =imdb_mean, sd = imdb_sd1)
#Якщо mean або sd не вказано, вони приймають значення за замовчуванням 0 і 1, відповідно
#rnorm генерує випадкові відхилення , генерує значення для нормального розподілу

movie_body_counts$imdb_simulation <- imdb_simulation

ggplot(movie_body_counts, aes(x=imdb_simulation)) +
geom_histogram(bins=10, color="grey", fill="lightgreen")


ggplot(movie_body_counts, aes(sample = imdb_simulation)) +
  stat_qq()









#Завдання 1-5
ggplot(movie_body_counts, aes(x=IMDB_Rating)) +
geom_histogram(bins=10, color="grey", fill="lightgreen")

ggplot(movie_body_counts, aes(sample = IMDB_Rating)) +
  stat_qq()
#Ні не є нормальним

ggplot(movie_body_counts, aes(x=imdb_simulation)) +
geom_histogram(bins=10, color="grey", fill="lightgreen")

y <-seq(2,11,by=0.01)
plot(y,dnorm(y,imdb_mean,imdb_sd1),col="red",type="l",xlab="X",
     	ylab="P(X)")

pnorm(4,imdb_mean,imdb_sd1)
pnorm(4,imdb_mean,imdb_sd1,lower.tail = FALSE)
pnorm(8,imdb_mean,imdb_sd1)-pnorm(4,imdb_mean,imdb_sd1)

ggplot(movie_body_counts, aes(x=IMDB_Rating, y=Body_Count)) +
 geom_point() 

imdb_sd1<-sd(movie_body_counts$IMDB_Rating)
imbd_sd2<-sd(movie_body_counts$Body_Count)
r=cov(movie_body_counts$IMDB_Rating,movie_body_counts$Body_Count)/(imdb_sd1*imbd_sd2)
r
cor(movie_body_counts$IMDB_Rating,movie_body_counts$Body_Count)

summary(lm(formula = movie_body_counts$IMDB_Rating~movie_body_counts$Body_Count))
#y=0.0008*x+6.77486
#На 1 вбитого більше то рейтинг стає на 0.0008

c<-movie_body_counts%>%filter(grepl("Action", movie_body_counts$Genre))
cor(c$IMDB_Rating,c$Body_Count)
h<-movie_body_counts%>%filter(grepl("Horror", movie_body_counts$Genre))
cor(h$Body_Count,h$IMDB_Rating)


