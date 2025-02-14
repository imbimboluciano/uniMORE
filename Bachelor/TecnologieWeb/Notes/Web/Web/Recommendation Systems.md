### What is recommendation system?
Based on a recommendation engine, a recommendation system is a mathematical model or objective function able to predict how much a “user will like” an item.

![[recommandationSystem.png]]

1. **User-based collaborative filtering**
    Collaborative filtering methods are based on collecting and analyzing a large amount of  
	information on users’ behaviors, activities or preferences (eg. ratings) and predicting  
	what users will like based on their similarity to other users. Model very simple and good performance ma the limit is that is not applicable for new items (cold start problem).
	![[userbasedsystem.png]]
2. **Content-based filtering**  
	Content-based filtering methods are based on a description of the item and a profile of the user’s preference. In a content-based recommendation system, keywords are used to describe the items. No need of item’s ratings but more complex to implement, unless  
	you consider the users’ relations to compute similarities (work on feature's item)	![[contentbased.jpg]]
3. **Hybrid Recommendation Sytems**
	Hybrid methods combine some feature of user-based system and some of content-based to overcome the common problems such as cold start.


### Why recommendation system?  
1. Two-thirds of movies watched by Netflix customers are recommended movies  
2. 38% of click-through rates on Google News are recommended links  
3. 35% of sales at Amazon arise from recommended products