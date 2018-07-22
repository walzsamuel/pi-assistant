<template>
    <div id="app">
        <Nav></Nav>
        <transition name="fade-anim">
            <router-view/>
        </transition>
    </div>
</template>

<script>
import Nav from '@/components/Nav.vue';

export default {
    components: { Nav },
    template: Nav,
};
</script>

<style>
    .fade-anim-enter-active {
        animation: coming .7s;
        animation-delay: .5s;
        opacity: 0;
    }

    .fade-anim-leave-active {
        animation: going .5s;
    }

    @keyframes going {
        from {
            transform: translateX(0);
        }
        to {
            transform: translateX(-30px);
            opacity: 0;
        }
    }

    @keyframes coming {
        from {
            transform: translateX(-30px);
            opacity: 0;
        }
        to {
            transform: translateX(0px);
            opacity: 1;
        }
    }
</style>
