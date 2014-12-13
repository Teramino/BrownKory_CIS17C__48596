//
//  SelfOrganizingList.h
//  _17C Midterm
//
//  Created by Kory Brown on 11/9/14.
//  Copyright (c) 2014 Kory Brown. All rights reserved.
//

#ifndef _17C_Midterm_SelfOrganizingList_h
#define _17C_Midterm_SelfOrganizingList_h

#include "LnkdLst.h"


template<class T>
class Organizer : public LnkdLst
{
public:
    bool seek(LnkdLst & list, T find)
    {
        Node *prev = list.getFirstNode();
        firstNode = list.getFirstNode();
//        Node *temp = new Node;
        if (firstNode->data == find)
        {
            return true;
        }
        else
        {
            worker = firstNode->next;
            while(true)
            {
                if (worker == NULL)
                {
                    cout << "Nodes don't contain data\n";
                    return false;
                }
                else if (worker->data == find)
                {
//                    temp->data = find;
//                    temp->next = fNode;
                    prev->next = worker->next;
                    worker->next = firstNode;
                    firstNode = worker;
                    list.setFirstNode(firstNode);
                    
                    return true;
                }
                else
                {
                    prev = worker;
                    worker = worker->next;
                }
            }
        }
         return false;
    }
};
#endif
