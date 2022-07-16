# Anime game metadata extractor
A simple program that allows you to decrypt and encrypt the metadata file of a certain anime game. It's very primitive, so don't expect great stability
# Usage
1. Grab a copy of the executable [here](https://github.com/Vivi029/anime-game-metadata-extractor/releases/tag/1.0) and save it somewhere on your computer
2. Once that's done open a terminal in the same location as the executable.
3. You are now ready to use the tool.
## Example usage
A simple command to decrypt a metadata file
```bash
metadata-extractor -i global-metadata.dat -o output.bin --decrypt
```
A simple command to encrypt a metadata file
```bash
metadata-extractor -i input.bin -o global-metadata-modified.dat --encrypt
```
# Parameters
Here's a list of all available parameters for this tool
```bash
-i <filename> #To specify the metadata file to open
-o <filename> #To specify where to write the processed metadata file
--encrypt #To set the tool in encryption mode
--decrypt #To set the tool en decryption mode
```
# Credits
[Cultivation dev team](https://github.com/Grasscutters/Cultivation) for ~95% of the code used in this tool
