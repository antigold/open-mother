# C = COUNTER
# METADATA : C STRING C STRING C STRING C STRING
# TILES : C X C Y C TEXTURENAME

#thx chatgpt
def int_to_hex_and_bytes_required(value):
    # Convert to hexadecimal string (without the '0x' prefix)
    hex_value = hex(value)[2:]  # Strip '0x'

    if len(hex_value) % 2 != 0:
        hex_value = "0" + hex_value

    # Calculate the number of bytes required
    bytes_required = (value.bit_length() + 7) // 8  # Ceiling of bits / 8

    return hex_value, bytes_required

def writestring(file, string):
    file.write(len(string).to_bytes(1, byteorder='big'))
    if isinstance(string, str):
        file.write(string.encode('ascii'))
    else:
        file.write(string)

def writeint(file, integer):
    hexval, brequired = int_to_hex_and_bytes_required(integer)
    file.write(brequired.to_bytes(1, byteorder='big'))
    file.write(bytes.fromhex(hexval))

def savefile(tilesend):
    magic = b"omm"
    mapname = b"Test Map"
    musicpath = b"music/test.ogg"
    musicname = b"testing music"
    musicauthor = b"kiromiaw"
    if (len(magic) > 255 or len(mapname) > 255 or len(musicpath) > 255 or len(musicname) > 255 or len(musicauthor) > 255):
        print("metadata names are too long! please limit to 255 chars")
        return
    with open('map.omm', 'wb') as file:
        # write metadata first
        writestring(file, magic)
        writestring(file, mapname)
        writestring(file, musicpath)
        writestring(file, musicname)
        writestring(file, musicauthor)

        # amt of tiles
        writeint(file, len(tilesend))

        for tile in tilesend:
            writeint(file, tile.x)
            writeint(file, tile.y)
            writestring(file, "swag")
        

if __name__ == "__main__":
    savefile([])