//Try 3:
class StockPrice {
   // unordered_map<int,int> mp;
    map<int,int> mp;
    map<int,int, greater<int>> dec;   //for greater/smallest recoding
   // int latest_price;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
       // latest_price=price;
        if(mp.find(timestamp)!=mp.end())//key doen't alreday exit
        {
            int old_price=mp[timestamp];
            //dec.erase(old_price);
            if((--dec[old_price])==0) dec.erase(old_price); //dec the count if it becomes 0 it means we don't have any other timestap that has same price as the current one we are delling with, so we can del it
        }
        mp[timestamp]=price;
        //dec.insert({price,timestamp});
        dec[price]++;//enter new {price, count} in map if not already existing, If existing just increment the count

    }
    
    int current() {  //curr is updated price of the greatest timestamp, so used 'mp' of type map instead of unordered map
        //return latest_price;
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return dec.begin()->first; //returns iterator to the firest key value   dec.beign()
    }
    
    int minimum() {
        return dec.rbegin()->first; //returns iterator to the last key value   dec.rbeign()
    }
};




//TRY 2:
//There is an issue -> we acuttly don't need to store timestamp in 'dec'.second      rather, there can be multiple timestamps that have same price
//so instead of going towards mulimap we can store count of price that occure
//for multiple timestamp

// class StockPrice {
//    // unordered_map<int,int> mp;
//     map<int,int> mp;
//     map<int,int, greater<int>> dec;   //for greater/smallest recoding
//    // int latest_price;
// public:
//     StockPrice() {
        
//     }
    
//     void update(int timestamp, int price) {
//        // latest_price=price;
//         if(mp.find(timestamp)!=mp.end())//key doen't alreday exit
//         {
//             int old_price=mp[timestamp];
//             dec.erase(old_price);
//         }
//         mp[timestamp]=price;
//         dec.insert({price,timestamp});

//     }
    
//     int current() {  //curr is updated price of the greatest timestamp, so used 'mp' of type map instead of unordered map
//         //return latest_price;
//         return mp.rbegin()->second;
//     }
    
//     int maximum() {
//         return dec.begin()->first; //returns iterator to the firest key value   dec.beign()
//     }
    
//     int minimum() {
//         return dec.rbegin()->first; //returns iterator to the last key value   dec.rbeign()
//     }
// };


//TRy 1:



// class StockPrice {
//     map<int,int> acc;
//     unordered_map<int,int> mp;
//     map<int,int, greater<int>> dec;
//     int latest_price;
// public:
//     StockPrice() {
        
//     }
    
//     // void update(int timestamp, int price) {
//     //     latest_price=price;
//     //     if(dec.find(timestamp)==dec.end())//key doen't alreday exit
//     //     {
//     //         dec.insert({timestamp,price});
//     //         acc.insert({timestamp,price});
//     //     }
//     //     else
//     //     {
//     //         dec[timestamp]=price;//will update the .second
//     //         acc[timestamp]=price;
//     //     }
//     // }
//         void update(int timestamp, int price) {
//         latest_price=price;
//         if(mp.find(timestamp)==mp.end())//key doen't alreday exit
//         {
//             mp.insert({timestamp,price});
//             dec.insert({price,timestamp});
//             acc.insert({price,timestamp});
//         }
//         else 
//         {
//             int old_price=mp[timestamp];
//             dec.erase(old_price);
//             acc.erase(old_price);
//             dec.insert({price,timestamp});
//             acc.insert({price,timestamp});
//             mp[timestamp]=price;
//         }
//     }
    
//     int current() {
//         return latest_price;
//     }
    
//     int maximum() {
//         return dec.begin()->first; //returns iterator to the firest key value   dec.beign()
//     }
    
//     int minimum() {
//         return acc.begin()->first; //returns iterator to the firest key value   dec.beign()
//     }
// };

// /**
//  * Your StockPrice object will be instantiated and called as such:
//  * StockPrice* obj = new StockPrice();
//  * obj->update(timestamp,price);
//  * int param_2 = obj->current();
//  * int param_3 = obj->maximum();
//  * int param_4 = obj->minimum();
//  */

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */