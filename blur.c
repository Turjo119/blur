// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create copy of original image
    RGBTRIPLE copy[height][width];
    // Copy each pixel to copy
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            copy[x][y].rgbtRed = image[x][y].rgbtRed;
            copy[x][y].rgbtGreen = image[x][y].rgbtGreen;
            copy[x][y].rgbtBlue = image[x][y].rgbtBlue;
        }
    }

        // For each row
    for (int i = 0; i < height; i++)
    {
        // For each pixel
        for (int j = 0; j < width; j++)
        {
            // Variiables for RGB calcualtions
            float sumRed = 0.0;
            float sumGreen = 0.0;
            float sumBlue = 0.0;

            // Top-Left corner
            if((i == 0) && (j == 0))
            {
               image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4.0);
               image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 4.0);
               image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4.0);
            }

            // Top-right corner
            else if((i == 0) && (j == width - 1))
            {
               image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 4.0);
               image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 4.0);
               image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 4.0);
            }

            // Bottom-left corner
            else if((i == height - 1) && (j == 0))
            {
               image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 4.0);
               image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen) / 4.0);
               image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue) / 4.0);
            }

            // Top-right corner
            else if((i == height - 1) && (j == width - 1))
            {
               image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed) / 4.0);
               image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen) / 4.0);
               image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue) / 4.0);
            }
            // For middle pixel values
            else if ( (0 < i < (height - 1)) && (0 < j < (width - 1)) )
            {

                for (int row = i - 1; row < i + 2; row++)
                {
                    for (int colm = j - 1; colm < j + 2; colm++)
                    {
                        sumRed = sumRed + copy[row][colm].rgbtRed;
                        sumGreen = sumGreen + copy[row][colm].rgbtGreen;
                        sumBlue = sumBlue + copy[row][colm].rgbtBlue;
                    }
                }
                image[i][j].rgbtRed = round(sumRed / 9.0);
                image[i][j].rgbtGreen = round(sumGreen / 9.0);
                image[i][j].rgbtBlue = round(sumBlue / 9.0);
            }

            // top edge
            else if ((i == 0) && (0 < j < width - 1))
            {
                image[i][j].rgbtRed = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
            }

            // bottom edge
            else if ((i == height - 1) && (0 < j < width - 1))
            {
                image[i][j].rgbtRed = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtBlue = round(( copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed) / 6.0);
            }

            // left edge
            else if ((0 < i < height - 1) && (j = 0))
            {
                image[i][j].rgbtRed = round(( copy[i- 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round(( copy[i- 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round(( copy[i- 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);
            }

            // right edge
            else if ((0 < i < height - 1) && (j = width - 1))
            {
                image[i][j].rgbtRed = round(( copy[i- 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j - 1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round(( copy[i- 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round(( copy[i- 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue) / 6.0);

            }



        }

    }

    return;
}
