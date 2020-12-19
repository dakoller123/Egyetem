module Ora where

import Prelude hiding (all)

count :: (a -> Bool) -> [a] -> Int
count p l = length $ filter p l

all :: (a -> Bool) -> [a] -> Bool
all p = foldr ( (&&) . p ) True