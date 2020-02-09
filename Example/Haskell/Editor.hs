-- Contributed by Gnome, unfinished .. obviously ..

import System.IO

open :: [Char] -> IO ([Char])
open fn = do
    file <- openFile fn ReadMode
    contents <- hGetContents file
    return contents

main :: IO ()
main = do
    (x:xs) <- getLine
    if x == 'o'
        then do
            let path = tail xs
            file <- open path
            (x:xs) <- getLine
            if x == 'a'
                then do
                    putStrLn "Append"
                    newLine <- getLine
                    let newFileContents = file ++ "\n" ++ newLine
                    putStrLn newFileContents
                    -- outFile <- openFile path WriteMode
                    -- writeFile outFile newFileContents
                else
                    main
        else
            main