else //如果当前出战的马一样，因为是贪心，所以我方还是需要遍历一下，是否有更厉害的能赢
        // {
        //     vector<int>::iterator it = tianji.begin();
        //     for(; it != tianji.end(); ++it)
        //     {
        //         if(*it > king[0]) //如果找到了第一个能比对面马厉害的，就出战
        //         {
        //             win++;
        //             tianji.erase(it);
        //             king.erase(king.begin());
        //             break; //不需要再出战，需要break
        //         }
        //     }
        //     //如果遍历完后都没有找到能打赢对面的，那么就是平局
        //     if(it == tianji.end())
        //     {
        //         tianji.erase(tianji.begin());
        //         king.erase(king.begin());
        //     }
        // }