#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...)
{
	    va_list args;
	        va_start(args, format);

		    if (format == NULL)
			        {
					        va_end(args);
						        return -1; // Handle the case where format is NULL
							    }

		        int count = 0; // To keep track of the number of characters printed

			    for (int i = 0; format[i] != '\0'; i++)
				        {
						        if (format[i] == '%')
								        {
										            i++;
											                if (format[i] == 'c')
														            {
																                    char c = va_arg(args, int);
																		                    write(1, &c, 1);
																				                    count++;
																						                }
													            else if (format[i] == 's')
															                {
																		                char *str = va_arg(args, char *);
																				                write(1, str, strlen(str));
																						                count += strlen(str);
																								            }
														                else if (format[i] == '%')
																	            {
																			                    write(1, "%", 1);
																					                    count++;
																							                }
																            // Add more cases for other format specifiers as needed
																        }
							        else
									        {
											            write(1, &format[i], 1);
												                count++;
														        }
								    }

			        va_end(args);

				    return count;
}

