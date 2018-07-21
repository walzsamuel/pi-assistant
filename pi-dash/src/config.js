// export const domain = 'http://' + document.location.hostname;

// Developement
export default {
    API_LOCATION: (process.env.NODE_ENV === 'development') ? 'http://pi-assistant/' : '',
    // API_LOCATION: 'http://192.168.0.199',
};
