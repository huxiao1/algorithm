for (auto i:graph)
        {
            if (map.find(i) == map.end())
            {
                queue.push(i);
                res.push_back(i);
            }
        }