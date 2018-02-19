#Чистим екран
cat("\014")
library(dplyr)
library(ggplot2) 
library(knitr) 
L <- 5;
data <- read.csv(
  "./_DATA/Лабораторні/flats.csv", 
  stringsAsFactors=FALSE, 
  dec= ",", 
  encoding="UTF-8"
);

cat("-=( ЛАБА 6, ВАРІАНТ", L,")=-\n")
cat("\n")


cat("-=( 1 )=-\n")
cat("Розмірність датафрейму: ", 
    dim(data)[1], "рЯдків, ", 
    dim(data)[2], "стовпців.", "\n");

cat("\n")
cat("-=( 2 )=-\n")
cat("Перші 6 рЯдків:", "\n");
print(head(data, n=6));

cat("\n")
cat("Перші 15 рЯдків:", "\n");
print(head(data, n=15));

cat("\n")
cat("Останні 6 рЯдків:", "\n");
print(head(data, n=6));

cat("\n")
cat("-=( 3 )=-\n")
cat("Імена:", "\n");
cat(names(data), sep=", ")
cat("\n")

cat("\n")
cat("-=( 4 )=-\n")
cat("В наборі flats", ncol(data), "змінних", "\n");


cat("\n")
cat("-=( 5 )=-\n")
cat("В наборі flats", length(table(data$Місто)), "міст:", "\n\t");
cat(unique(data$Місто), sep="\n\t");

cat("\n")
cat("-=( 6 )=-\n")
print(
  data %>% slice(grep("Києво-*", Місто, invert = TRUE)) %>% count(Місто)
)

cat("\n")
cat("-=( 7 )=-\n")
cat(
  "В Одесі продеєтьсЯ", 
  (data %>% filter(Місто == "Одеса") %>% filter(Кімнат == 3) %>% count(Місто)) $ n, 
  "трикімнатних квартир",
  "\n"
)

cat("\n")
cat("-=( 8 )=-\n")
cat(
  "Медіана площ однокімнатних квартир у Львові:", 
  (data %>% filter(Кімнат == 1) %>% filter(Місто == "Львів") %>% 
     group_by(Місто) %>% summarise(median=median(Загальна_площа))
   ) $ median,
  "\n"
)


cat("\n")
cat("-=( 9 )=-\n")
cat("Залежність цін від кількості кімнат", "\n")
ggplot(data, aes(x=factor(Кімнат), y=Ціна)) + 
  geom_boxplot() +
  coord_flip() + 
  xlab('Kімнат')

cat("\n")
cat("-=( 10 )=-\n")
cat("Залежність ціни від загальної площі", "\n")
ggplot(data, aes(x=Загальна_площа, y=Ціна)) +
  geom_point()

cat("\n")
cat("-=( 11 )=-\n")
cat("Гістограма длЯ оцінки розподілу ціни квартир", "\n")
ggplot(data, aes(x=Ціна)) +  
  geom_histogram(bins=50, fill="lightblue", col="grey") + 
  ylab("Кількість")
