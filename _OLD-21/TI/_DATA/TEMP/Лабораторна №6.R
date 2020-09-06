library(dplyr)
library(ggplot2)
flats <- read.csv("flats.csv", stringsAsFactors=FALSE, encoding="UTF-8",dec= ",")
#encoding="UTF-8" використовується для коректноговідображення кирилиці у OS Windows. 
#stringsAsFactors=FALSE вказує, що змінні, які мають тип character не будуть перетворюватись у тип даних factor.
class(flats)
str(flats)

#Завдання 1-3*
dim(flats)
head(flats,6)
head(flats,15)
tail(flats,6)
names(flats)
#----------------------------------------------------------*

glimpse(flats)
summary(flats)
flats %>%count(Місто) %>%arrange(n)

#Завдання 4-8 ----------------------------------------------*
ncol(flats)
count(flats,Місто)
length(table(flats$Місто))
n_distinct(flats$Місто)
unique(flats$Місто)
flats%>%filter(Місто != "Києво-Святошинський")%>%count(Місто)

flats%>%filter(Місто == "Одеса")%>%filter(Кімнат == 3)%>%count(Місто)

flats %>%filter(Кімнат == 1) %>%filter(Місто == "Львів") %>%
  group_by(Місто)%>%summarise(median_1_flats=median(Загальна_площа))
#-----------------------------------------------------------*

ggplot(flats, aes(x=Загальна_площа)) +
  geom_histogram(breaks=seq(0, 250, by = 25),fill="lightblue",col="grey") 
+ylab("Кількість")

#Завдання 9-11---------------------------------------------*
flats$price_in_USD <-flats$floor(Ціна/25.0)
flats$price_in_USD_floor<-floor(flats$price_in_USD)
ggplot(flats, aes(price_in_USD_floor))+ 
  geom_histogram(bins = 30,fill="lightblue",col="grey")+ylab("Кількість")

ggplot(flats, aes(x=Загальна_площа, y=Ціна)) +
  geom_point() 

ggplot(flats, aes(x=factor(Кімнат), y=Ціна)) +geom_boxplot() +
  coord_flip()+xlab('Kімнат')
#-----------------------------------------------------------*

